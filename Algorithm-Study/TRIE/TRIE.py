# Enter your code here. Read input from STDIN. Print output to STDOUT

import sys
import codecs

sys.stdin = codecs.getreader("utf-8")(sys.stdin.detach())
sys.stdout = codecs.getwriter("utf-8")(sys.stdout.detach())

T = int(sys.stdin.readline().rstrip())

import random

for t in range(T):
    songs = sys.stdin.readline().rstrip().split('\t')

    artists = sys.stdin.readline().rstrip().split('\t')

    dic = {}
    max_num_songs = 0
    for i in range(len(artists)):
        artist = artists[i]
        if artist not in dic:
            dic[artist] = []
        
        dic[artist].append(songs[i])
        if(max_num_songs < len(dic[artist])):
            max_num_songs = len(dic[artist])
            max_num_artist = artist
    
    dummy = 'dummy'
    song_matrix = []
    for artist in list(dic.keys()):
        for _ in range(max_num_songs - len(dic[artist])):
            dic[artist].append(dummy)
        song_matrix.append(dic[artist])
    

    for artist in list(dic.keys()):
        print(len(dic[artist]))
    

    random.shuffle(songs)
    print('\t'.join(songs))
    


