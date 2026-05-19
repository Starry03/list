
use clap::Parser;

#[derive(Debug, Parser)]
pub struct Args {
    /// set path
    #[arg(short, long, default_value = ".")]
    pub path: String,

    /// show version
    #[arg(short, long, default_value_t = false)]
    pub version: bool,

    /// show hidden files
    #[arg(short('a'), long("all"), default_value_t = false)]
    pub hidden: bool,

    /// show file permissions
    #[arg(short('l'), long("l"), default_value_t = false)]
    pub permissions: bool,

    /// show file size
    #[arg(short, long, default_value_t = false)]
    pub size: bool,

    /// show items count
    #[arg(short, long, default_value_t = false)]
    pub count: bool,

    /// recursive
    #[arg(short, long, default_value_t = false)]
    pub recursive: bool,
}