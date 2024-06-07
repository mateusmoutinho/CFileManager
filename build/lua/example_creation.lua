

function Create_examples()
       dtw.remove_any(EXAMPLES_FOLDER)
	   local test_tree = dtw.newTree_from_hardware(TEST_POINT)
	   test_tree.each(function (tree_part)
	        local path = tree_part.path

	        if path.get_name() ~= "exec.c" then
	        	return
	        end
            path.insert_dir_at_index(0,EXAMPLES_FOLDER)
            path.remove_dir_at(TEST_POINT)
            local final_name =  path.get_sub_dirs_from_index(-1,-1)
            final_name = clib.replace(final_name,"T_","")
            final_name = clib.replace(final_name,"S_","")
            final_name = clib.replace(final_name,"/",".c")
            path.remove_sub_dir_at_index(-1,-1)
            path.set_name(final_name)

            --tree_part.hardware_write()
            clib.print(path.get_full_path().."\n")
	   end)
	   
end