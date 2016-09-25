(* #use "fonctions.ml" *)

let separe l = 
  let rec aux l acc = 
      match l with
      |[] -> acc
      |h::[] -> (match acc with 
	|(l1, l2) -> (l1 @ [h], l2)
      )
      |h1::h2::t -> match acc with
	|(l1, l2) -> aux t (l1 @ [h1], l2 @ [h2])
  in
  aux l ([], [])
;;

let fusion l1 l2 = 
  let rec aux l1 l2 acc = 
    match (l1, l2) with 
    |([], []) -> acc
    |(h::t, []) -> aux t [] (acc @ [h])
    |([], h::t) -> aux t [] (acc @ [h])
    |(h1::t1, h2::t2) -> 
      if h1 < h2 then
	aux t1 l2 (acc @ [h1])
      else
	aux l1 t2 (acc @ [h2])
  in

  aux l1 l2 []
;;


type t_degre = |Celsius |Fahrenheit;;

let conversion temp = 
  match temp with
  |(Celsius, valeur) -> (Fahrenheit, 32. +. 9. /. 5. *. valeur)
  |(Fahrenheit, valeur) -> (Celsius, 5. /. 9. *. valeur -. 17.78)
;;

let superieur t1 t2 =
  match (t1, t2) with ((a, b), (c, d)) ->
    if(a == c) then
      t1 > t2
    else
      t1 > conversion t2
;;
