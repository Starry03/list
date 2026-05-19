use list::direntry::direntry_cmp;
use toml;
use clap::Parser;
use walkdir::WalkDir;
use std::io;
use std::io::Write;
use std::path::Path;

use list::args::Args;
use list::cargo_lock::CargoLock;
use list::icon::build_icons_cache;
use list::writer::{self, clean_key};

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args = Args::parse();

    if args.version {
        let cargo_lock: CargoLock = toml::from_str(&std::fs::read_to_string("Cargo.toml")?)?;
        println!("{} version {}", cargo_lock.package.name, cargo_lock.package.version);
        return Ok(());
    }

    list_path(&args)?;

    return Ok(());
}

fn list_path(args: &Args) -> Result<(), Box<dyn std::error::Error>> {
    let path = Path::new(&args.path);
    let icons_cache = build_icons_cache("./storage/icons.csv".to_string());

    if path.is_file() {
        println!("{}", path.display());
        return Ok(());
    }

    let walker = WalkDir::new(path).max_depth(if args.recursive { usize::MAX } else { 1 });
    let stdout = io::stdout();
    let mut handle = stdout.lock();

    for entry in walker.sort_by(&direntry_cmp) {
        let entry = entry?;

        let name = entry.file_name();
        if args.hidden == false && name.to_str().unwrap().starts_with(".") {
            continue;
        }
        let ext = entry.path().extension();
        let key: String;
        if ext.is_none() {
            key = clean_key(&name.to_str().unwrap());
        } else {
            key = ext.unwrap().to_str().unwrap().to_string();
        }
        let mut icon = icons_cache.get(&key);
        if icon.is_none() && entry.file_type().is_dir() {
            icon = icons_cache.get("_folder");
        }
        writer::write_align(&mut handle, entry.depth())?;
        writer::write_filename(&mut handle, name.to_str().unwrap(), icon)?;
        if args.permissions {
            write!(handle, "\t{}", writer::get_permissions_string(entry.path()))?;
        }
        write!(handle, "\n")?;
    }

    Ok(())
}

