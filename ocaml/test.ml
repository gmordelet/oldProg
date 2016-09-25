let t l = 
  match l with
  |[] -> 1
  |h::t -> 2
  |h1::[h2]::t -> 3
;;
