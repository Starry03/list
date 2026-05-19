use std::collections::HashMap;

use serde::Deserialize;

#[derive(Deserialize)]
pub struct Icon {
    pub group: String,
    pub icon: String,
    pub color: String,
}

pub fn build_icons_cache(path: String) -> HashMap<String, Icon> {
    let mut rdr = csv::Reader::from_reader(std::fs::File::open(path).unwrap());
    let mut icons: HashMap<String, Icon> = HashMap::new();
    for res in rdr.records() {
        let record = res.unwrap();
        icons.insert(record[1].to_string(), Icon {
            group: record[0].to_string(),
            icon: record[2].to_string(),
            color: record[3].to_string(),
        });
    }
    return icons;
}