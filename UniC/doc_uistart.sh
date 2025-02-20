#!/usr/bin/bash

stop() {
	echo "stopping doc UI"
	kill $client_pid $backend_pid
}

trap stop SIGINT

# client
cd ./doc/client && npm run start &
client_pid=$!

# backend
cd ./doc/backend && go run main.go &
backend_pid=$!

wait $client_pid $backend_pid

