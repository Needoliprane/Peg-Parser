# Peg-Parser


Il s'agit d'un parser PEG avec un stockage style heap. Il est adaptable à tous les parsing : 
1. Bistro-matic
2. Minishell
3. etc...

Le focntionnement est simple : 
Une structure grammar : 
- allowed char : tous les chars autorisées
- grammar char : tous les chars de grammaire
une structure de control qui contient un tableau de structure
- les 2 string autour du grammar char
- et le char de grammaire
- + différent élements pour remplir el tableau

une fois la tructure initialisé le parsing peut commencer.
Pour une implémentation : 
1. peg_set_grammar(grammar_char, allowed_char)
2. peg_alloc(char *str, la structure avec la grammaire)
3. peg_print(la strcutre control_peg)
4. [optionnel] peg_print
5. peg_destroy(grammar, peg_control)


test : ./compiler_script

./peg "....."

Le comportement est imprésible si il y a 2 char de grammaire à la suite. Il faudra donc clean la string avant l'utilisation
