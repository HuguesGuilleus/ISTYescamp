#!/bin/bash

# The server and the adress: login@server
SERV=21702988@einstein.isty.uvsq.fr
SERV=21702988@darwin.isty.uvsq.fr

rsync -av --delete --exclude-from .gitignore --exclude ".git/" \
	./ $SERV:~/escampeTest &&
echo "*** Upload réussi ***" &&
ssh -X $SERV "cd escampeTest/ && ./build.bash netoyage"
