#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

MODULE_INFO(intree, "Y");

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x531bf32a, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x964b601a, __VMLINUX_SYMBOL_STR(kobject_put) },
	{ 0x413c01e4, __VMLINUX_SYMBOL_STR(blkdev_issue_discard) },
	{ 0xd5d786e, __VMLINUX_SYMBOL_STR(kset_create_and_add) },
	{ 0xa9df11dd, __VMLINUX_SYMBOL_STR(kmem_cache_destroy) },
	{ 0x8dfd488a, __VMLINUX_SYMBOL_STR(fs_bio_set) },
	{ 0xd99a8d9d, __VMLINUX_SYMBOL_STR(iget_failed) },
	{ 0x2ffca66, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xbedf11d1, __VMLINUX_SYMBOL_STR(new_sync_write) },
	{ 0x8e83ea20, __VMLINUX_SYMBOL_STR(perf_tp_event) },
	{ 0x405c1144, __VMLINUX_SYMBOL_STR(get_seconds) },
	{ 0x3138c945, __VMLINUX_SYMBOL_STR(drop_nlink) },
	{ 0xe10b6827, __VMLINUX_SYMBOL_STR(submit_bio_wait) },
	{ 0xc94351df, __VMLINUX_SYMBOL_STR(generic_getxattr) },
	{ 0x579eabae, __VMLINUX_SYMBOL_STR(up_read) },
	{ 0x4cb99946, __VMLINUX_SYMBOL_STR(bio_alloc_bioset) },
	{ 0xf3a1f5af, __VMLINUX_SYMBOL_STR(make_bad_inode) },
	{ 0x714c039, __VMLINUX_SYMBOL_STR(generic_file_llseek) },
	{ 0xda3e43d1, __VMLINUX_SYMBOL_STR(_raw_spin_unlock) },
	{ 0x54a1ec5a, __VMLINUX_SYMBOL_STR(__mark_inode_dirty) },
	{ 0x3ab3de9, __VMLINUX_SYMBOL_STR(debugfs_create_dir) },
	{ 0x270f0310, __VMLINUX_SYMBOL_STR(__set_page_dirty_nobuffers) },
	{ 0x4fdeacb9, __VMLINUX_SYMBOL_STR(filemap_fault) },
	{ 0xc1b398a, __VMLINUX_SYMBOL_STR(single_open) },
	{ 0x188a3dfb, __VMLINUX_SYMBOL_STR(timespec_trunc) },
	{ 0x754d539c, __VMLINUX_SYMBOL_STR(strlen) },
	{ 0x7091d6e2, __VMLINUX_SYMBOL_STR(generic_file_llseek_size) },
	{ 0x60a13e90, __VMLINUX_SYMBOL_STR(rcu_barrier) },
	{ 0xc7a1840e, __VMLINUX_SYMBOL_STR(llist_add_batch) },
	{ 0xcc277e09, __VMLINUX_SYMBOL_STR(filemap_write_and_wait_range) },
	{ 0xc8b57c27, __VMLINUX_SYMBOL_STR(autoremove_wake_function) },
	{ 0x9469482, __VMLINUX_SYMBOL_STR(kfree_call_rcu) },
	{ 0xf2e1de98, __VMLINUX_SYMBOL_STR(generic_fh_to_parent) },
	{ 0x79aa04a2, __VMLINUX_SYMBOL_STR(get_random_bytes) },
	{ 0x34184afe, __VMLINUX_SYMBOL_STR(current_kernel_time) },
	{ 0xba87dfd9, __VMLINUX_SYMBOL_STR(single_release) },
	{ 0x3fb8a666, __VMLINUX_SYMBOL_STR(seq_puts) },
	{ 0x1bd67f2d, __VMLINUX_SYMBOL_STR(is_bad_inode) },
	{ 0xb28ebd78, __VMLINUX_SYMBOL_STR(blkdev_issue_flush) },
	{ 0x8cf80ce4, __VMLINUX_SYMBOL_STR(pagecache_get_page) },
	{ 0xca34a823, __VMLINUX_SYMBOL_STR(truncate_inode_pages_range) },
	{ 0x4056dfdd, __VMLINUX_SYMBOL_STR(generic_file_open) },
	{ 0xd1a014b0, __VMLINUX_SYMBOL_STR(posix_acl_access_xattr_handler) },
	{ 0xacf4d843, __VMLINUX_SYMBOL_STR(match_strdup) },
	{ 0x7ab88a45, __VMLINUX_SYMBOL_STR(system_freezing_cnt) },
	{ 0x8b900f3b, __VMLINUX_SYMBOL_STR(_raw_read_lock) },
	{ 0x6cdf3710, __VMLINUX_SYMBOL_STR(__lock_page) },
	{ 0xd41a4adb, __VMLINUX_SYMBOL_STR(touch_atime) },
	{ 0xc0a3d105, __VMLINUX_SYMBOL_STR(find_next_bit) },
	{ 0xc08d90ac, __VMLINUX_SYMBOL_STR(dput) },
	{ 0x91831d70, __VMLINUX_SYMBOL_STR(seq_printf) },
	{ 0xde6fa2cb, __VMLINUX_SYMBOL_STR(generic_file_remap_pages) },
	{ 0xd3e0937c, __VMLINUX_SYMBOL_STR(remove_proc_entry) },
	{ 0x6729d3df, __VMLINUX_SYMBOL_STR(__get_user_4) },
	{ 0x44e9a829, __VMLINUX_SYMBOL_STR(match_token) },
	{ 0x448eac3e, __VMLINUX_SYMBOL_STR(kmemdup) },
	{ 0x2d5d2f69, __VMLINUX_SYMBOL_STR(inc_nlink) },
	{ 0xc1891a45, __VMLINUX_SYMBOL_STR(init_user_ns) },
	{ 0xc0e2aeba, __VMLINUX_SYMBOL_STR(filemap_fdatawait_range) },
	{ 0x8b0e7032, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xce3c6ef3, __VMLINUX_SYMBOL_STR(mount_bdev) },
	{ 0x85df9b6c, __VMLINUX_SYMBOL_STR(strsep) },
	{ 0x703dfdb2, __VMLINUX_SYMBOL_STR(kobject_del) },
	{ 0xc4980bcd, __VMLINUX_SYMBOL_STR(generic_read_dir) },
	{ 0x999e8297, __VMLINUX_SYMBOL_STR(vfree) },
	{ 0x3ecc7262, __VMLINUX_SYMBOL_STR(igrab) },
	{ 0xaaa5a95f, __VMLINUX_SYMBOL_STR(debugfs_create_file) },
	{ 0x4629334c, __VMLINUX_SYMBOL_STR(__preempt_count) },
	{ 0xb1493418, __VMLINUX_SYMBOL_STR(generic_setxattr) },
	{ 0xfe723618, __VMLINUX_SYMBOL_STR(redirty_page_for_writepage) },
	{ 0x6daf03da, __VMLINUX_SYMBOL_STR(debugfs_remove_recursive) },
	{ 0x419bdf68, __VMLINUX_SYMBOL_STR(seq_read) },
	{ 0x40c7247c, __VMLINUX_SYMBOL_STR(si_meminfo) },
	{ 0xa7272c48, __VMLINUX_SYMBOL_STR(set_page_dirty) },
	{ 0x39214c66, __VMLINUX_SYMBOL_STR(kthread_create_on_node) },
	{ 0x8eb0371e, __VMLINUX_SYMBOL_STR(truncate_setsize) },
	{ 0x9e7db4e4, __VMLINUX_SYMBOL_STR(mutex_trylock) },
	{ 0x3608f183, __VMLINUX_SYMBOL_STR(down_read) },
	{ 0xc0363765, __VMLINUX_SYMBOL_STR(end_page_writeback) },
	{ 0xc463b4e4, __VMLINUX_SYMBOL_STR(make_kgid) },
	{ 0xf432dd3d, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0x22717363, __VMLINUX_SYMBOL_STR(PDE_DATA) },
	{ 0x6d0aba34, __VMLINUX_SYMBOL_STR(wait_for_completion) },
	{ 0x5c46bbdb, __VMLINUX_SYMBOL_STR(inode_owner_or_capable) },
	{ 0xa7cdc1ff, __VMLINUX_SYMBOL_STR(mpage_readpages) },
	{ 0x3c80c06c, __VMLINUX_SYMBOL_STR(kstrtoull) },
	{ 0xbbe1aede, __VMLINUX_SYMBOL_STR(trace_define_field) },
	{ 0x22f9529, __VMLINUX_SYMBOL_STR(ftrace_event_buffer_commit) },
	{ 0xfb578fc5, __VMLINUX_SYMBOL_STR(memset) },
	{ 0x67bc8d49, __VMLINUX_SYMBOL_STR(from_kuid) },
	{ 0xc4b5c09, __VMLINUX_SYMBOL_STR(proc_mkdir) },
	{ 0x7b2baff4, __VMLINUX_SYMBOL_STR(mpage_readpage) },
	{ 0x8f64aa4, __VMLINUX_SYMBOL_STR(_raw_spin_unlock_irqrestore) },
	{ 0x36586807, __VMLINUX_SYMBOL_STR(current_task) },
	{ 0x830b0bfa, __VMLINUX_SYMBOL_STR(freezing_slow_path) },
	{ 0x746765b2, __VMLINUX_SYMBOL_STR(__bread_gfp) },
	{ 0x6b50e47d, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0xc23c7f40, __VMLINUX_SYMBOL_STR(kthread_stop) },
	{ 0x34b8e364, __VMLINUX_SYMBOL_STR(posix_acl_chmod) },
	{ 0xde880062, __VMLINUX_SYMBOL_STR(d_obtain_alias) },
	{ 0x449ad0a7, __VMLINUX_SYMBOL_STR(memcmp) },
	{ 0x121fe8df, __VMLINUX_SYMBOL_STR(iov_iter_alignment) },
	{ 0x534fac7e, __VMLINUX_SYMBOL_STR(bio_add_page) },
	{ 0x97856a99, __VMLINUX_SYMBOL_STR(kobject_init_and_add) },
	{ 0x479c3c86, __VMLINUX_SYMBOL_STR(find_next_zero_bit) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0xb81febbd, __VMLINUX_SYMBOL_STR(from_kgid) },
	{ 0x6e45d0ae, __VMLINUX_SYMBOL_STR(seq_putc) },
	{ 0xf529952e, __VMLINUX_SYMBOL_STR(security_inode_init_security) },
	{ 0x68b83ac6, __VMLINUX_SYMBOL_STR(posix_acl_alloc) },
	{ 0x5f3e89f3, __VMLINUX_SYMBOL_STR(debugfs_remove) },
	{ 0xcb2760cc, __VMLINUX_SYMBOL_STR(kmem_cache_free) },
	{ 0x93a6e0b2, __VMLINUX_SYMBOL_STR(io_schedule) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xec911f, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x47e214fd, __VMLINUX_SYMBOL_STR(set_nlink) },
	{ 0xaac0260d, __VMLINUX_SYMBOL_STR(file_update_time) },
	{ 0x6feb73e1, __VMLINUX_SYMBOL_STR(write_cache_pages) },
	{ 0x143687b2, __VMLINUX_SYMBOL_STR(_raw_write_lock) },
	{ 0x60df1e3b, __VMLINUX_SYMBOL_STR(posix_acl_equiv_mode) },
	{ 0x39a77281, __VMLINUX_SYMBOL_STR(page_symlink) },
	{ 0xb6ccc0ed, __VMLINUX_SYMBOL_STR(insert_inode_locked) },
	{ 0xfd2a6815, __VMLINUX_SYMBOL_STR(truncate_pagecache) },
	{ 0x1fd6bbf3, __VMLINUX_SYMBOL_STR(set_cached_acl) },
	{ 0x4e3567f7, __VMLINUX_SYMBOL_STR(match_int) },
	{ 0xf5bbf352, __VMLINUX_SYMBOL_STR(wait_on_page_bit) },
	{ 0x36f833ae, __VMLINUX_SYMBOL_STR(unlock_page) },
	{ 0x9d71fc50, __VMLINUX_SYMBOL_STR(generic_file_read_iter) },
	{ 0x680135f9, __VMLINUX_SYMBOL_STR(up_write) },
	{ 0x31518a04, __VMLINUX_SYMBOL_STR(shrink_dcache_sb) },
	{ 0x2dbfffd6, __VMLINUX_SYMBOL_STR(down_write) },
	{ 0xdc6f9ba9, __VMLINUX_SYMBOL_STR(__get_page_tail) },
	{ 0x3d51730b, __VMLINUX_SYMBOL_STR(posix_acl_create) },
	{ 0xdaddb7f, __VMLINUX_SYMBOL_STR(__brelse) },
	{ 0x3c483012, __VMLINUX_SYMBOL_STR(radix_tree_delete) },
	{ 0x45e81512, __VMLINUX_SYMBOL_STR(bio_put) },
	{ 0x6d85e154, __VMLINUX_SYMBOL_STR(generic_removexattr) },
	{ 0xa0e8e1a2, __VMLINUX_SYMBOL_STR(inode_init_once) },
	{ 0xd96eed98, __VMLINUX_SYMBOL_STR(ftrace_event_reg) },
	{ 0xeed631f8, __VMLINUX_SYMBOL_STR(page_follow_link_light) },
	{ 0xe1f687ba, __VMLINUX_SYMBOL_STR(mnt_drop_write_file) },
	{ 0xdd1a84b0, __VMLINUX_SYMBOL_STR(submit_bio) },
	{ 0xc6cbbc89, __VMLINUX_SYMBOL_STR(capable) },
	{ 0xbd9074b1, __VMLINUX_SYMBOL_STR(blk_finish_plug) },
	{ 0xe20372ae, __VMLINUX_SYMBOL_STR(radix_tree_gang_lookup) },
	{ 0x40a9b349, __VMLINUX_SYMBOL_STR(vzalloc) },
	{ 0x8eba3a95, __VMLINUX_SYMBOL_STR(kmem_cache_alloc) },
	{ 0xb2fd5ceb, __VMLINUX_SYMBOL_STR(__put_user_4) },
	{ 0xddb1cd7, __VMLINUX_SYMBOL_STR(llist_reverse_order) },
	{ 0x36847623, __VMLINUX_SYMBOL_STR(generic_block_fiemap) },
	{ 0x950bea78, __VMLINUX_SYMBOL_STR(fs_kobj) },
	{ 0x88b5e634, __VMLINUX_SYMBOL_STR(bdevname) },
	{ 0xf2748943, __VMLINUX_SYMBOL_STR(truncate_inode_pages_final) },
	{ 0xe87f0791, __VMLINUX_SYMBOL_STR(make_kuid) },
	{ 0xaccf8003, __VMLINUX_SYMBOL_STR(pagevec_lookup_tag) },
	{ 0x3bd1b1f6, __VMLINUX_SYMBOL_STR(msecs_to_jiffies) },
	{ 0xd62c833f, __VMLINUX_SYMBOL_STR(schedule_timeout) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0x96b29254, __VMLINUX_SYMBOL_STR(strncasecmp) },
	{ 0x251ad51f, __VMLINUX_SYMBOL_STR(unlock_new_inode) },
	{ 0x948e5c09, __VMLINUX_SYMBOL_STR(mnt_want_write_file) },
	{ 0x8b8059bd, __VMLINUX_SYMBOL_STR(in_group_p) },
	{ 0xcec87b5b, __VMLINUX_SYMBOL_STR(kill_block_super) },
	{ 0xcb4bf16f, __VMLINUX_SYMBOL_STR(inode_newsize_ok) },
	{ 0x550517a5, __VMLINUX_SYMBOL_STR(page_cache_sync_readahead) },
	{ 0x4482cdb, __VMLINUX_SYMBOL_STR(__refrigerator) },
	{ 0x82887488, __VMLINUX_SYMBOL_STR(wake_up_process) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
	{ 0x56fa6162, __VMLINUX_SYMBOL_STR(vfs_setpos) },
	{ 0xc0e6bdb6, __VMLINUX_SYMBOL_STR(clear_page_dirty_for_io) },
	{ 0xc881c0a0, __VMLINUX_SYMBOL_STR(inode_change_ok) },
	{ 0x25378e4a, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0xd52bf1ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0x9327f5ce, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irqsave) },
	{ 0x86465cd6, __VMLINUX_SYMBOL_STR(ftrace_event_buffer_reserve) },
	{ 0x10950ee1, __VMLINUX_SYMBOL_STR(radix_tree_tag_clear) },
	{ 0x53402273, __VMLINUX_SYMBOL_STR(new_sync_read) },
	{ 0x98d2a973, __VMLINUX_SYMBOL_STR(kmem_cache_create) },
	{ 0xb6b8cfa3, __VMLINUX_SYMBOL_STR(d_tmpfile) },
	{ 0x3e5daf36, __VMLINUX_SYMBOL_STR(register_filesystem) },
	{ 0x88db5201, __VMLINUX_SYMBOL_STR(generic_file_write_iter) },
	{ 0x8860253a, __VMLINUX_SYMBOL_STR(event_triggers_call) },
	{ 0xcf21d241, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xb3f7646e, __VMLINUX_SYMBOL_STR(kthread_should_stop) },
	{ 0x92c6477a, __VMLINUX_SYMBOL_STR(__pagevec_release) },
	{ 0x34f22f94, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x1fb1eeb4, __VMLINUX_SYMBOL_STR(__test_set_page_writeback) },
	{ 0x58b9557c, __VMLINUX_SYMBOL_STR(proc_create_data) },
	{ 0x4f68e5c9, __VMLINUX_SYMBOL_STR(do_gettimeofday) },
	{ 0xab3d27e5, __VMLINUX_SYMBOL_STR(iter_file_splice_write) },
	{ 0xe39445e3, __VMLINUX_SYMBOL_STR(seq_lseek) },
	{ 0xb9c1243, __VMLINUX_SYMBOL_STR(kset_unregister) },
	{ 0x64aedccc, __VMLINUX_SYMBOL_STR(iput) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0xf233a451, __VMLINUX_SYMBOL_STR(d_find_any_alias) },
	{ 0xb4dcaaba, __VMLINUX_SYMBOL_STR(ihold) },
	{ 0x69acdf38, __VMLINUX_SYMBOL_STR(memcpy) },
	{ 0x2a4e1c3c, __VMLINUX_SYMBOL_STR(__sb_end_write) },
	{ 0xdbacda67, __VMLINUX_SYMBOL_STR(trace_event_raw_init) },
	{ 0xa75312bc, __VMLINUX_SYMBOL_STR(call_rcu_sched) },
	{ 0x5c8b5ce8, __VMLINUX_SYMBOL_STR(prepare_to_wait) },
	{ 0xd498a358, __VMLINUX_SYMBOL_STR(d_splice_alias) },
	{ 0xd0a91bab, __VMLINUX_SYMBOL_STR(skip_spaces) },
	{ 0xe6602e9f, __VMLINUX_SYMBOL_STR(perf_trace_buf_prepare) },
	{ 0x25376ec2, __VMLINUX_SYMBOL_STR(sync_filesystem) },
	{ 0x246e88f4, __VMLINUX_SYMBOL_STR(invalidate_mapping_pages) },
	{ 0x7ea702f0, __VMLINUX_SYMBOL_STR(sb_set_blocksize) },
	{ 0xe20214df, __VMLINUX_SYMBOL_STR(__sb_start_write) },
	{ 0x87c9bc71, __VMLINUX_SYMBOL_STR(generic_readlink) },
	{ 0x7628f3c7, __VMLINUX_SYMBOL_STR(this_cpu_off) },
	{ 0xf19282c9, __VMLINUX_SYMBOL_STR(put_page) },
	{ 0xe13ae006, __VMLINUX_SYMBOL_STR(d_make_root) },
	{ 0x7a4497db, __VMLINUX_SYMBOL_STR(kzfree) },
	{ 0xf03e27db, __VMLINUX_SYMBOL_STR(__blockdev_direct_IO) },
	{ 0xb352177e, __VMLINUX_SYMBOL_STR(find_first_bit) },
	{ 0xfa66f77c, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x844e3767, __VMLINUX_SYMBOL_STR(radix_tree_lookup) },
	{ 0x318f7b5e, __VMLINUX_SYMBOL_STR(posix_acl_default_xattr_handler) },
	{ 0x47b6a10f, __VMLINUX_SYMBOL_STR(ftrace_print_symbols_seq) },
	{ 0x7980abae, __VMLINUX_SYMBOL_STR(unregister_filesystem) },
	{ 0x90ef106f, __VMLINUX_SYMBOL_STR(init_special_inode) },
	{ 0xf3038a60, __VMLINUX_SYMBOL_STR(filemap_map_pages) },
	{ 0x4b06d2e7, __VMLINUX_SYMBOL_STR(complete) },
	{ 0x28318305, __VMLINUX_SYMBOL_STR(snprintf) },
	{ 0x54add4ac, __VMLINUX_SYMBOL_STR(new_inode) },
	{ 0x1e3a88fb, __VMLINUX_SYMBOL_STR(trace_seq_printf) },
	{ 0xb0e602eb, __VMLINUX_SYMBOL_STR(memmove) },
	{ 0x19a214fe, __VMLINUX_SYMBOL_STR(generic_file_splice_read) },
	{ 0x5287a6a1, __VMLINUX_SYMBOL_STR(generic_fh_to_dentry) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x9f4b2964, __VMLINUX_SYMBOL_STR(grab_cache_page_write_begin) },
	{ 0x614bb773, __VMLINUX_SYMBOL_STR(radix_tree_insert) },
	{ 0x7a071583, __VMLINUX_SYMBOL_STR(clear_inode) },
	{ 0x7d705738, __VMLINUX_SYMBOL_STR(blk_start_plug) },
	{ 0x83f766df, __VMLINUX_SYMBOL_STR(page_put_link) },
	{ 0xa2779881, __VMLINUX_SYMBOL_STR(d_instantiate) },
	{ 0x992e786f, __VMLINUX_SYMBOL_STR(ftrace_raw_output_prep) },
	{ 0x67ffaad0, __VMLINUX_SYMBOL_STR(__init_rwsem) },
	{ 0xa231eadd, __VMLINUX_SYMBOL_STR(generic_block_bmap) },
	{ 0xebd98a24, __VMLINUX_SYMBOL_STR(clear_nlink) },
	{ 0x90cc3f9f, __VMLINUX_SYMBOL_STR(iget_locked) },
	{ 0xbfb4ca7f, __VMLINUX_SYMBOL_STR(generic_fillattr) },
	{ 0xd3e88b77, __VMLINUX_SYMBOL_STR(filemap_fdatawrite) },
	{ 0xf20a6e7f, __VMLINUX_SYMBOL_STR(inode_init_owner) },
	{ 0xe2304e87, __VMLINUX_SYMBOL_STR(truncate_inode_pages) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "6B19F8663B25C6C05645DEC");
