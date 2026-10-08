# MASTERMIND
***

## Task
Le programme consiste en la création d'un serveur renvoyant plusieurs informations en fonction des requêtes envoyées

## Description
Express est utilisé pour créer et connecter le serveur.

Les requêtes sont récupérées avec app.get() et les réponses sont envoyées avec res.send() et res.redirect()
On utilise req.headers.authorization pour récupérer les informations d'authentification

## Installation
Require("express.js") est requis pour créer et connecter le serveur sur le port 8080. 
Le programme est lancé avec node.js

## Usage
Dans le terminal, les requêtes sont envoyées avec curl.
