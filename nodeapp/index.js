const express = require('express');
const app = express();

const port = 3000;
const host = 'localhost';

app.set('views', './views');
app.set('view engine', 'pug');

app.get('/', (req, res) => {
	res.render('index');
});

app.listen(port, host, () => {
	console.log(`Server started at ${host} port ${port}`);
});​