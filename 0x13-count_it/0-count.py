#!/usr/bin/python3
"""
recursive function
that queries the Reddit API,
parses the title of all hot articles,
and prints a sorted count of given keywords
case-insensitive, delimited by spaces.
Javascript should count as javascript,
but java should not)
"""
import requests


def count_words(subreddit, word_list):
    """
    recursive function that queries the Reddit API,
    parses the title of
    all hot articles,
    and prints a sorted
    count of given keywords
    """
    r = requests.get('https://www.reddit.com/r/{}/hot/.json'.format(subreddit),
                     headers={'User-agent': 'Chrome'})
    data = {}
    title_name = []
    ct = {}
    for word in word_list:
        if word not in ct:
            ct[word] = 0
    if r.status_code == 200:
        children = r.json().get('data').get('children')
        for item in children:
            title_name.append(item.get('data').get('title'))
        for title in title_name:
            for k, v in ct.items():
                copy = title[:]
                cut = copy.lower().split(k.lower())
                ct[k] += len(cut) - 1
        duplicates = {}
        for k in ct:
            if ct[k] == 0:
                pass
            elif k.lower() in duplicates:
                duplicates[k.lower()] += ct[k]
            else:
                duplicates[k.lower()] = ct[k]
        sorted_values = sorted(duplicates.values(), reverse=True)
        sorted_dict = {}

        for i in sorted_values:
            for k in duplicates.keys():
                if duplicates[k] == i:
                    sorted_dict[k] = duplicates[k]
        for i in sorted_dict.keys():
            print("{}: {}".format(i, sorted_dict[i]))
