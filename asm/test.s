.name "I am the NAME "   #Le commentaire le plus long du monde
.comment "The commentaire myfriend"

first:	sti r1, %2, r2
		live %12345678
		and r1, %2, r2
second:	sti r1, %:first , r2
