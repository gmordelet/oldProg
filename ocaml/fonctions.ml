(*
print_list_int l : Afficher liste de int
print_list_char l : Afficher liste de char
print_bool b : Afficher booléen
*)

let  print_list_int l = 
  print_char('[');
  let rec print_list_int1 l1 = 
    if l1 = [] then 
      begin
	print_char(']');
      end
    else 
      begin
	print_int(List.hd l1);
	if List.tl l1 <> [] then print_char(';');
	print_list_int1(List.tl l1)
      end
  in
  print_list_int1 l
;;

let  print_list_char l = 
  print_char('[');
  let rec print_list_char1 l1 = 
    if l1 = [] then 
	print_char(']')
    else 
      begin
	print_char(List.hd l1);
	if List.tl l1 <> [] then print_char(';');
	print_list_char1(List.tl l1)
      end
  in
  print_list_char1 l
;;


let print_bool b = 
  if b then 
    print_string"true"
  else 
    print_string"false"
;;
