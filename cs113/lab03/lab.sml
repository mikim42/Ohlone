"ex 3.3";
val L0 = ¬ p ´ q ¤ ³p ² q ®;
val conditional = prove_rule [] L0;
val L1 = rewrite_rule [conditional] (asm_rule ¬ ³ (p ´ q) ®);
rewrite_rule [³_²_thm] L1;
