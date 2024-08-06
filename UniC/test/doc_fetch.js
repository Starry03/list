ENDPOINT = "https://api.github.com/repos/Starry03/UniC/contents/doc/doc.json"
fetch(ENDPOINT)
	.then(response => response.json())
	.then(data => {
		console.log(data);
		console.log(atob(data.content));
	})