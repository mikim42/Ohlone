"ex 3.3";
val L0 = � p � q � �p � q �;
val conditional = prove_rule [] L0;
val L1 = rewrite_rule [conditional] (asm_rule � � (p � q) �);
rewrite_rule [�_�_thm] L1;
