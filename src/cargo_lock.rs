use serde::Deserialize;

#[derive(Deserialize)]
pub struct Package {
    pub name: String,
    pub version: String,
}

#[derive(Deserialize)]
pub struct CargoLock {
    pub package: Package,
}