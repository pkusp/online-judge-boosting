import re
import logging
import os
from bs4 import BeautifulSoup
import bs4
import requests


top100_url = "https://leetcode.com/problemset/top-100-liked-questions/"

headers = {
    ":authority": "www.nowcoder.com",
    ":method": "GET",
    ":path": top100_url,
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



def get_content(url):
    # url = "https://www.nowcoder.com/discuss/54773?type=2&order=0&pos=68&page=1"
    page_res = requests.get(url)
    soup = BeautifulSoup(page_res.text, "html.parser")
    print('-------')
    content = soup.find_all(class_="reactable-data")
    content = str(content)
    return content


def save_content(contents):
    with open("ms_interview.md",mode='w') as f:
        for content in contents:
            f.write(content.replace("\n","")+"\n")


def main():
    res = get_content(top100_url)
    print(res)

if __name__ == "__main__":
    main()
