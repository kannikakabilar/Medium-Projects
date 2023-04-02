const express = require('express');
const mongoose = require('mongoose');

const uri = "mongodb+srv://kanns1999:KannikaSoftwareEngineer99@mongoexpresscluster.zbimusl.mongodb.net/?retryWrites=true&w=majority";

async function connect () {
    try {
        await mongoose.connect(uri);
        console.log("Connected to MongoDB");
    } catch (e) {
        console.error(e);
    }
}

connect();

const app = express();
app.listen(8080, () => {
    console.log("Server Started");
});