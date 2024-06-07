



local function main()

        local src_sha = dtw.generate_sha_from_folder_by_content(LIB_FOLDER)
        local cache = NewCache(CACHE_POINT)

        local amalgamation_cache = cache.new_element("amalgamation",function ()
            return Generate_amalgamation_recursive(START_POINT)
        end).add_dependencie(src_sha)


        local amalgamation_result = amalgamation_cache.perform()
        dtw.write_file(END_TEST_POINT,amalgamation_result)

        Execute_full_test(cache,src_sha)

        local locker_content= dtw.load_file("tests/locker_test/locker_test.c")

       cache.new_element("locker",function ()
            Execute_locker_test()
        end).
        add_dependencie(locker_content).
        add_dependencie(src_sha).
        perform()


        Create_examples()




        clib.print(ANSI_RESET)




        --local readme = Create_readme()
        --dtw.write_file("README.md",readme)

end

main()