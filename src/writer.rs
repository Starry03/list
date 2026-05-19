use std::io::Write;

use crate::icon::Icon;

pub fn write_tab(handle: &mut std::io::StdoutLock, depth: usize) -> std::io::Result<()> {
    if depth == 0 {
        return Ok(());
    }
    write!(handle, "{}", "\t".repeat(depth - 1))?;
    Ok(())
}

pub fn write_filename(handle: &mut std::io::StdoutLock, name: &str, icon: Option<&Icon>) -> std::io::Result<()> {
    if icon.is_none() {
        writeln!(handle, "{}", name)?;
    } else {
        writeln!(handle, "{} {}", icon.unwrap().icon, name)?;
    }
    Ok(())
}

pub fn clean_key(key: &str) -> String {
    return key.replacen(".", "", 1);
}
