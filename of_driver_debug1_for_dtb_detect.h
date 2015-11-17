diff --git a/drivers/of/fdt.c b/drivers/of/fdt.c
index d16fb86..8de03a4 100644
--- a/drivers/of/fdt.c
+++ b/drivers/of/fdt.c
@@ -1012,6 +1012,7 @@ int __init __weak early_init_dt_reserve_memory_arch(phys_addr_t base,
 
 bool __init early_init_dt_scan(void *params)
 {
+	printk("zz %s params:%p \n", __func__, params);
 	if (!params)
 		return false;
 
@@ -1020,6 +1021,7 @@ bool __init early_init_dt_scan(void *params)
 
 	/* check device tree validity */
 	if (be32_to_cpu(initial_boot_params->magic) != OF_DT_HEADER) {
+		printk("zz %s magic error\n", __func__);
 		initial_boot_params = NULL;
 		return false;
 	}
@@ -1032,6 +1034,7 @@ bool __init early_init_dt_scan(void *params)
 
 	/* Setup memory, calling early_init_dt_add_memory_arch */
 	of_scan_flat_dt(early_init_dt_scan_memory, NULL);
+	printk("zz %s true\n", __func__);
 
 	return true;
 }
