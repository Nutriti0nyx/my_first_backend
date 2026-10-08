const express = require('express');
const app = express();
const port = 8080;
function fromFranky() {
    return ["My Way Of Life","My Way","Daybreak","That's Life","This Is No Dream","Tina","To Love A Child","Triste","The Train","Volare","Wave","Who","You And I","You And Me","You Walk By","Young At Heart","Elizabeth","Empty Tables","Exodus","Dry Your Eyes"][Math.round(Math.random()*19)]
}
app.get('/', (req, res) => {
    res.send(fromFranky());
});
app.get('/birth_date', (req, res) => {
    res.send("December 12, 1915");
});
app.get('/birth_city', (req, res) => {
    res.send("Hoboken, New Jersey");
});
app.get('/wives', (req, res) => {
    res.send("Nancy Barbato, Ava Gardner, Mia Farrow, Barbara Marx");
});
app.get('/picture', (req, res) => {
    res.redirect("https://en.wikipedia.org/wiki/Frank_Sinatra#/media/File:Frank_Sinatra2,_Pal_Joey.jpg");
});
app.get('/public', (req, res) => {
    res.send("Everybody can see this page");
});
app.get('/protected', (req, res) => {
    try {
        auths = atob(req.headers.authorization.split(' ')[1]).split(":")
        if (auths[0] == "admin" && auths[1] == "admin") {
            res.send("Welcome, authenticated client")
        } }
    finally {
        res.status(401).send("Not authorized.");
    }
});
app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});