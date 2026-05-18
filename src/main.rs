use list::args::Args;
use list::cargo_lock::CargoLock;
use toml;
use clap::Parser;

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let args = Args::parse();

    if args.version {
        let cargo_lock: CargoLock = toml::from_str(&std::fs::read_to_string("Cargo.toml")?)?;
        println!("{} version {}", cargo_lock.package.name, cargo_lock.package.version);
        return Ok(());
    }

    

    return Ok(());
}
