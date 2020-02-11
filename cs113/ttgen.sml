fun ttgen_ex((a:'a,b:'a),[]) = [] | 
    ttgen_ex((a:'a,b:'a), q::qs : 'a list list) = 
        [q @ [a]] @ [q @ [b]] @ ttgen_ex((a,b), qs) : 'a list list;

fun ttgen(0, (_, _)) = [[]] : 'a list list |
    ttgen(1, (a:'a,b:'a)) = [[a],[b]] |
    ttgen(d, (a:'a,b:'a)) = ttgen_ex((a,b), ttgen(d-1, (a,b)));
