# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# question 1

La lib std::filesystem sert à gérer les fichiers et dossiers directement en C++, sans passer par des commandes système ou des chemins en texte dur. Elle permet de faire plein de trucs comme vérifier si un fichier existe (exists), créer des dossiers (create_directories), parcourir des répertoires (directory_iterator), copier, renommer ou supprimer des fichiers (copy_file, rename, remove_all).

Ce qui est pratique c’est que c’est portable, donc ça marche autant sur Windows que sur Linux sans changer les / ou \. Dans mon code, elle est utilisée pour faire les sauvegardes automatiques (books.txt.backup, users.txt.backup). Avant on aurait fait ça avec des fstream, mais là c’est beaucoup plus simple et propre. En plus elle gère les erreurs avec std::error_code au lieu de tout planter en exception. Bref c’est une lib moderne et pratique, et c’est cool de la voir en action dans ce TP.

# question 2

Si la biblio devenait géante comme celle d’Alexandrie, je ferais plus ça juste en C++. J’utiliserais un serveur web (genre en Python) avec une vraie base de données pour stocker les millions de livres. Le C++ servirait juste de petit client (comme une borne à la biblio) qui envoie et reçoit les infos via internet.
Le serveur s’occuperait de tout le gros boulot (sauvegarde, recherche, etc.) et le C++ garderait juste l’interface simple pour les usagers. Ce serait plus rapide, plus propre et ça pourrait grossir sans tout casser.