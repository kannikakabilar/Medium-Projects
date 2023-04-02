var express = require('express');
var app = express();

// Note3: making the middleware function global middleware
app.use(logger);

/* Note1: The function inside the app.get is essentially a middleware because
it happens before the server sends ot a response to the client but 
after receiving a request
*/
app.get('/', function(req, res){
   console.log("Home Page"); // Gets logged on console 2nd - depending on url
   res.send("Home Page");
});

// Note6: app.get can take in multiple functions as middleware
app.get('/users', auth, function(req, res){
   console.log("Users Page"); // Gets logged on console 2nd - depending on url *(3rd after Note5)
   console.log(`User is admin = ${req.admin}`) // Note7: Part2
   res.send("Users Page");
});

// Note2: middleware function
function logger(req, res, next) {
   console.log("Log"); // Gets logged on console 1st
   // By calling next, we are calling the next piece of middleware in-line
   next();
}

// Note5: Another type of middleware function
function auth(req, res, next) {
   //Note7: Performing authentication
   if (req.query.admin === 'true'){
      req.admin = true; // Setting it to access in next middleware
      next();  // when url is http://localhost:8080/users?admin=true
   }else{
      res.send("No authentication");  // when url is: http://localhost:8080/users
   }
   console.log("Auth"); // Gets logged on console 2nd
   //next(); // next() does not act like a return function, code after next() will get executed or cause error
}

app.listen(8080);

// Note4: Goto http://localhost:8080/users and click refresh to see what gets logged in the console