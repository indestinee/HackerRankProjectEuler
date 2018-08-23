import os, sys

try:
    index = sys.argv[1]
    url = 'https://www.hackerrank.com/contests/projecteuler/challenges/euler%s/problem' % index
except:
    print('[ERR] Usage: ./update.sh problem_id(xxx)')
    exit(-1)

if not os.path.isdir(index):
    os.mkdir(index)
# if not os.path.isfile(index):
with open(index + '/README.md', 'w') as f:
        f.write('\
# <a href=\'%s\'> Problem Link </a>\n\
# main algorithm: \n\
    0. \
' % url);


