let verifier_matrice matrice = 
  let rec aux matrice taille = 
    match matrice with
    |[] -> true
    |ligne::t -> if List.length ligne <> taille then
	false
      else
	aux t taille	
  in

  match matrice with 
  |[] -> true
  |ligne::t -> 
    let taille = List.length ligne in
    aux matrice taille
;;

let afficher_matrice matrice = 
  let rec afficher_ligne ligne = 
    match ligne with
    |h::[] -> print_float h; print_newline ()
    |h::t -> print_float h; print_string "; "; afficher_ligne t
    |[] -> ()
  in

  let rec afficher_matrice_rec matrice = 
    match matrice with
    |[] -> ()
    |h::t -> afficher_ligne h; afficher_matrice_rec t
  in

  if not(verifier_matrice matrice) then
    print_string "Matrice invalide\n"
  else
    afficher_matrice_rec matrice
;;

let float_aleatoire abs =
  let signe_int = Random.int 2 in
  let signe = if signe_int == 1 then 1. else -1. in
  Random.float abs *. signe
;;

let rec matrice_aleatoire lignes colonnes abs = 
  let rec lignes_aleatoire colonnes abs acc = 
    if colonnes == 0 then 
      acc 
    else 
      lignes_aleatoire (colonnes - 1) abs ((float_aleatoire abs)::acc)
  in

  let rec aux lignes colonnes abs acc = 
    if lignes == 0 then
      acc
    else
      aux (lignes - 1) colonnes abs (lignes_aleatoire colonnes abs []::acc)
  in

  Random.self_init ();
  aux lignes colonnes abs [];
;;

let taille_colonnes matrice = 
  match matrice with 
  |[] -> 0
  |h::t -> List.length h
;;

let taille_lignes matrice = 
  List.length matrice
;;

let rec retourner_ligne matrice ligne = 
  match matrice with 
  |[] -> []
  |h::t -> 
    if ligne == 1 then
      h
    else
      retourner_ligne t (ligne - 1)
;;

let retourner_colonne matrice colonne =
  let rec aux matrice colonne lignes acc = 
    if lignes == 0 then 
      acc
    else 
      match matrice with
      |[] -> []
      |h::t -> aux t colonne (lignes - 1) (acc @ [List.nth h (colonne - 1)])
  in
  
  let lignes = List.length matrice in
  aux matrice colonne lignes []
;;

let multiplication_vecteurs v1 v2 = 
  let rec aux l1 l2 acc = 
    match (l1, l2) with
    |([], []) -> acc
    |(h1::t1, h2::t2) -> aux t1 t2 (acc +. h1 *. h2)
    |(_, []) -> 0.
    |([], _) -> 0.
  in
  
  aux v1 v2 0.
;;

let construction_matrice list lignes colonnes = 
  let construction_ligne list colonnes = 
    let rec aux list colonnes acc = 
      match colonnes with
      |0 -> (acc, list)
      |_ -> match list with 
	|[] -> (acc, [])
	|h::t -> aux t (colonnes - 1) (acc @ [h])
    in
    aux list colonnes []
  in

  let rec aux list lignes colonnes acc = 
    match lignes with 
    |0 -> acc
    |_ -> match construction_ligne list colonnes with (accL, resteListe) -> 
      aux resteListe (lignes - 1) colonnes (acc @ [accL])
  in

  aux list lignes colonnes []
;;

let multiplication_matrice matrice1 matrice2 = 
  let rec construction_ligne matrice1 matrice2 ligne colonne acc =
    match colonne with 
    |0 -> acc
    |_ -> construction_ligne matrice1 matrice2 ligne (colonne - 1) ((multiplication_vecteurs (retourner_ligne matrice1 ligne) (retourner_colonne matrice2 colonne))::acc)
  in

  let rec aux matrice1 matrice2 lignes colonnes acc = 
    match lignes with
    |0 -> acc
    |_ -> aux matrice1 matrice2 (lignes - 1) colonnes 
      ([construction_ligne matrice1 matrice2 lignes colonnes []] @ acc)
  in

  aux matrice1 matrice2 (taille_lignes matrice1) (taille_colonnes matrice2) []
;;
