const express = require('express');
const app = express();
const port = 3000;

app.set('views', './views');
app.set('view engine', 'pug');

app.get('/', (req, res, next) => {
	res.render('index');
});

app.get('/member/:name/planet/:home', (req, res) => {
	const memberDetails = {
		member: req.params.name,
		planet: req.params.home
	}
	res.render('index', memberDetails);
});

app.get('*', (req, res, next) => {
	res.status(200).send('Sorry, page not found');
	next();
});

app.listen(port, () => {
	console.log(`Server started at port ${port}`);
});