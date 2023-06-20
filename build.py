
import CToolKit as ct
from shutil import copytree,rmtree
from os import remove
from os import listdir



STARTER = 'doTheWorld/doTheWorldMain.h'
OUTPUT_TEST = 'doTheWorld_test.h'



def execute_test_for_folder(folder:str):
    files = listdir(folder)
    for file in files:
        #means its an destructive side effect script
        if '#destructive#' in file:
            rmtree('security',ignore_errors=True)
            copytree('exemple_folder','security')
            try:
                ct.execute_test_for_file('gcc',f'{folder}/{file}')
            except Exception as e:
                rmtree('exemple_folder',ignore_errors=True)
                copytree('security','exemple_folder')
                rmtree('security',ignore_errors=True)
                raise e
        else:
            ct.execute_test_for_file('gcc',f'{folder}/{file}')
        print('passed:',file)

    print(files)

def  execute_all_tests():
    execute_test_for_folder('exemples/io')

ct.generate_amalgamated_code(STARTER,OUTPUT_TEST)
execute_all_tests()





