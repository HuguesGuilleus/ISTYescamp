# Escampe

# Auteur
Les fichiers `vue/graphics.c`, `vue/graphics.h` et `vue/couleur.h` ont été conçu par Franck QUESSETTE et Laurence PILARD.

Le fichier `build.bash` est issue du fichier `Makefile` donné avec les fichiers cités précédemment de Franck QUESSETTE et Laurence PILARD.

Les autres fichiers ont été écrit par:
- Maxime VINCENT
- Hugues GUILLEUS

## Compilation
Pour compiler veuillez utiliser `build.bash` à la racine du projet qui compile tous les fichiers `.c`, crée l'exécutable `escampe` et le lance.

Exemple:
```bash
# À la racine du projet
$ ./build.bash
```

Pour supprimer les fichiers objets, il faut lancer `build.bash` avec l'argument `clean`.
```bash
# À la racine du projet
$ ./build.bash clean
```
