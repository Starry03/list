use std::cmp::Ordering;

pub fn direntry_cmp(a: &walkdir::DirEntry, b: &walkdir::DirEntry) -> std::cmp::Ordering {
    if a.file_type().is_dir() && b.file_type().is_file() {
        return Ordering::Less;
    } else if a.file_type().is_file() && b.file_type().is_dir() {
        return Ordering::Greater;
    }
    return a.file_name().cmp(b.file_name());
}