use std::io::Write;
use std::fs;
#[cfg(unix)]
use std::os::unix::fs::PermissionsExt;
use crate::icon::Icon;

fn ansi_color(color: &str) -> &'static str {
    match color {
        "black" => "\x1b[38;2;0;0;0m",
        "red" => "\x1b[38;2;178;34;34m",
        "green" => "\x1b[38;2;34;139;34m",
        "yellow" => "\x1b[38;2;219;200;0m",
        "blue" => "\x1b[38;2;70;130;180m",
        "magenta" => "\x1b[38;2;199;21;133m",
        "cyan" => "\x1b[38;2;0;206;209m",
        "white" => "\x1b[38;2;245;245;245m",
        "orange" => "\x1b[38;2;255;165;0m",
        "pink" => "\x1b[38;2;255;192;203m",
        "purple" => "\x1b[38;2;128;0;128m",
        "brown" => "\x1b[38;2;165;42;42m",
        "olive" => "\x1b[38;2;128;128;0m",
        "teal" => "\x1b[38;2;0;128;128m",
        "navy" => "\x1b[38;2;0;0;128m",
        "gray" => "\x1b[38;2;128;128;128m",
        _ => "",
    }
}

#[cfg(unix)]
pub fn get_permissions_string(path: &std::path::Path) -> String {
    match fs::metadata(path) {
        Ok(metadata) => {
            let mode = metadata.permissions().mode();
            format!(
                "{}{}{}{}{}{}{}{}{}",
                if mode & 0o400 != 0 { 'r' } else { '-' },
                if mode & 0o200 != 0 { 'w' } else { '-' },
                if mode & 0o100 != 0 { 'x' } else { '-' },
                if mode & 0o040 != 0 { 'r' } else { '-' },
                if mode & 0o020 != 0 { 'w' } else { '-' },
                if mode & 0o010 != 0 { 'x' } else { '-' },
                if mode & 0o004 != 0 { 'r' } else { '-' },
                if mode & 0o002 != 0 { 'w' } else { '-' },
                if mode & 0o001 != 0 { 'x' } else { '-' },
            )
        }
        Err(_) => "---------".to_string(),
    }
}

#[cfg(not(unix))]
pub fn get_permissions_string(_path: &std::path::Path) -> String {
    "N/A".to_string()
}

pub fn write_align(handle: &mut std::io::StdoutLock, depth: usize) -> std::io::Result<()> {
    if depth == 0 {
        return Ok(());
    }
    write!(handle, "{}", "\t".repeat(depth - 1))?;
    Ok(())
}

pub fn write_filename(handle: &mut std::io::StdoutLock, name: &str, icon: Option<&Icon>) -> std::io::Result<()> {
    if icon.is_none() {
        write!(handle, "{}", name)?;
    } else {
        let icon = icon.unwrap();
        let color = ansi_color(icon.color.as_str());
        if color.is_empty() {
            write!(handle, "{} {}", icon.icon, name)?;
        } else {
            write!(handle, "{}{}\x1b[0m {}", color, icon.icon, name)?;
        }
    }
    Ok(())
}

pub fn clean_key(key: &str) -> String {
    return key.replacen(".", "", 1);
}
