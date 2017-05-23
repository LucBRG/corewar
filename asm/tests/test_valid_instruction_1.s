#let's go

            .comment     "Commentaire" # Le commentaire
.name       "VALID INSTRUCTION 1"	# Le name

label1:		live %1
			sti %:coucou
coucou:		sti r1, %2, r1
			zjmp %:monamie
monamie:	live %1
			zjmp %:coucou



label1:    live %1
	   		sti r1, %2, r1
	   	   	 zjump	:salut
salut:		live %2

=================
01 00 00 00 01
09 00 03
0b 64 01 00 02 01
=================

=================
01 00 00 00 01		#label 1
09 00 03			-> 3  -> coucou
0b 64 01 00 02 01	#coucou
09 00 03			-> 3  -> monamie
01 00 00 00 01		#monamie
09 ff  ea			-> 21 -> label1
==================

01 00 00 00 01		#label 1
09 00 03			-> 3  -> coucou
0b 64 01 00 02 01	#coucou
09 00 03			-> 3  -> monamie
01 00 00 00 01		#monamie
09 ff  f2			-> 13 -> coucou