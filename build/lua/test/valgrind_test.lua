

---@param cache Cache
---@param side_effect_sha string
---@param artifact TestSpec
 function Exec_valgrind_test(cache,side_effect_sha,artifact)
    local memory_tested = false
    cache.new_element(function ()
        memory_tested =true
        local comand = "valgrind --log-file='output_test' ./"..artifact.executable_path
        clib.system_with_string(comand);

        local result = dtw.load_file("output_test")
        if result == nil then
            Rebase_side_effect()
            clib.exit(1)
            return
        end

        local HEAP_CHECK  = "All heap blocks were freed -- no leaks are possible"
        local error =false
        if clib.indexof(result,HEAP_CHECK) == -1 then
        	error = true
        end
        local ERROR_CHECK = "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)"
        if clib.indexof(result,ERROR_CHECK) == -1 then
          error = true
        end

        Rebase_side_effect()
        if error then
            clib.print(ANSI_RED..result)
        	clib.exit(1)
        end
        clib.print(ANSI_GREEN.."\tmemory test:passed\n")
end).
    add_dependencie(artifact.executable_sha).
    add_dependencie(side_effect_sha).
    perform()

    if memory_tested == false then
        clib.print(ANSI_YELLOW.."\tmemory test:cached\n")
    end
end
