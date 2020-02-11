PolyML.print_depth 64;
val truth_values_1 = [0,1];
fun add_value_0 (v) = (0,v);
fun add_value_1 (v) = (1,v);
val truth_values_2 = map add_value_0 truth_values_1 @ 
                     map add_value_1 truth_values_1;
fun add_value_0 (v1,v2) = (0,v1,v2);
fun add_value_1 (v1,v2) = (1,v1,v2);
val truth_values_3 = map add_value_0 truth_values_2 @
                     map add_value_1 truth_values_2;
fun add_value_0 (v1,v2,v3) = (0,v1,v2,v3);
fun add_value_1 (v1,v2,v3) = (1,v1,v2,v3);
val truth_values_4 = map add_value_0 truth_values_3 @
                     map add_value_1 truth_values_3;
fun add_value_0 (v1,v2,v3,v4) = (0,v1,v2,v3,v4);
fun add_value_1 (v1,v2,v3,v4) = (1,v1,v2,v3,v4);
val truth_values_5 = map add_value_0 truth_values_4 @
                     map add_value_1 truth_values_4;