# encoding: utf-8
"""
@author: pkusp
@contact: pkusp@outlook.com

@version: 1.0
@file: interview_exp_new_coder.py
@time: 2019/11/24 6:20 PM

这一行开始写关于本文件的说明与解释
"""
import re
import logging
import os
from bs4 import BeautifulSoup
import bs4
import requests


ms_exp_url = '/discuss/tag/146?type=2&order=0&query='  ## type=2 interview_exp
exp_url = "https://www.nowcoder.com/discuss?type=2&order=0&pageSize=30&expTag=0&page="
root_url = 'https://www.nowcoder.com'


headers = {
    ":authority": "www.nowcoder.com",
    ":method": "GET",
    ":path": exp_url,
    ":scheme": "https",
    "accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3",
    "accept-encoding": "gzip, deflate, br",
    "accept-language": "en,zh-CN;q=0.9,zh;q=0.8",
    "cache-control": "max-age=0",
    "cookie": "NOWCODERUID=A480574C365E6F87685EDCCB285F4ED9; NOWCODERCLINETID=6916FFBC7097D08C3158EA483A076A36; Hm_lvt_a808a1326b6c06c437de769d1b85b870=1574588687; Hm_lpvt_a808a1326b6c06c437de769d1b85b870=1574591238; SERVERID=11b18158070cf9d7800d51a2f8a74633|1574591238|1574588683",
    "sec-fetch-mode": "navigate",
    "sec-fetch-site": "none",
    "sec-fetch-user": "?1",
    "upgrade-insecure-requests": "1",
    "user-agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_5) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/77.0.3865.90 Safari/537.36",

}


def get_url_list():
    page = 'https://www.nowcoder.com/discuss/tag/146?type=2&order=0&pageSize=30&expTag=0&query=&page='
    # type:interview_exp
    # pos: topic position
    # page:page
    exp = 'https://www.nowcoder.com/discuss/315360?type=2&order=0&pos=5&page=1'
    url_list = []
    for i in range(4):
        base_url = page+str(i)
        page_res = requests.get(base_url)
        if page_res.status_code == 200:
            soup = BeautifulSoup(page_res.text, "html.parser")
            for tag in soup.find_all("a"):
                title = tag.text
                title_url = tag.attrs["href"]
                if (title.find("面经")!=-1 or title.find("凉经")!=-1) and title.find("微软")!=-1:
                    print(title)
                    print(i,'===============')
                    res_url = root_url+title_url
                    url_list.append((title,res_url))
    return url_list


def merge_blank(s):
    res = ""
    for i in range(len(s)-1):
        if s[i] == ' ' and s[i+1] == ' ':
            continue
        res+=s[i]
        if s[i]=="\\" and s[i+1]=="n":
            i+=2

    return res


def get_content(url):
    # url = "https://www.nowcoder.com/discuss/54773?type=2&order=0&pos=68&page=1"
    page_res = requests.get(url)
    soup = BeautifulSoup(page_res.text, "html.parser")
    print('-------')
    content = soup.find_all(class_="post-topic-des nc-post-content")
    content = str(content)
    del_string = re.findall("<.*?>",content)
    for dels in set(del_string):
        content = content.replace(dels,"")

    return merge_blank(content)


def save_content(contents):
    with open("ms_interview.txt",mode='w') as f:
        for content in contents:
            f.write(content.replace("\n","")+"\n")


def main():
    ms_interview = [ ]
    url_list = get_url_list()
    for title,url in url_list:
        text = get_content(url)
        ms_interview.append(("url: ["+url+"] title: ["+title+"] \ncontent: "+text))
    print(ms_interview)
    save_content(ms_interview)


if __name__ == "__main__":
    main()



