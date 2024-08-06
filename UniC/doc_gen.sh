#!/bin/bash

.venv/bin/python doc/docfile_gen.py
if [ $? == 0 ];
	then echo "Documentation generated successfully"
else
	echo "Documentation generation failed"
fi
