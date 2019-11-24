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
import tqdm
# from pyquery import PyQuery as pq


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
                    url_list.append(res_url)
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
    with open("ms_interview.text",mode='w') as f:
        for content in contents:
            f.write(content+"\n")


def main():
    ms_interview = [ ]
    url_list = get_url_list()
    for url in url_list:
        text = get_content(url)
        ms_interview.append((url+" : "+text))
    print(ms_interview)
    save_content(ms_interview)


if __name__ == "__main__":
    main()







#
# def save_excel_url():
#     save_list = []
#     url_list = get_url_list()
#     for url_tuple in url_list:
#         url = url_tuple[1]
#         country = url_tuple[0]
#         print("正在获取[{}]的EXCEL地址:".format(country))
#         headers = {
#             'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8',
#             'Accept-Encoding': 'gzip, deflate, br',
#             'Accept-Language': 'en,zh-CN;q=0.9,zh;q=0.8',
#             'Cache-Control': 'max-age=0',
#             'Connection': 'keep-alive',
#             'Cookie': '_ga=GA1.3.1250981148.1530342937; _gid=GA1.3.942515468.1530342937; uvts=7gXZC41o09odqcs5; _4c_=fVLZbuM4EPwVgcDmyaF46KAMGIEvJNlFHORYAzMvBi9bgmXJoaQoB%2FLvadqZILPBjh6obrJYXdXsV9TntkJDGnPCYyKSKEmSAdra5wYNX5He%2B%2FXRL3eraS6rypbBUrpCqtKiITJWB33tShMoWW0DI1sZvOSBfWrRAHWuBEjetvtmGIb%2BDB%2BwHoprt8G6CnXdVa17DlXetbI6eyxsP9K5dP7%2BxLbyrmh9nQWkytV9Yx1k09zVOxskKezq2ngAzTDHEeRrUIwoi0kmKI0EPhiLWMY9uAZT6EpqCJ1dW%2BcOdL8U9n2PlSxMh3W9C8ui2p6BhdGlndyz23XzsNPnz%2Fstm427evrPy8OinNWb6u95stD9YpX%2FPNXdD7XcXXaL5enF3L10bT9bRpvHk96MTuxDYUYmZUqwtSaEJAlhFv7%2B47HiKWReYXP0%2B1ufYLu1bue1Q3h9dX%2B7mszH0%2BvFV%2B1qU9ZKltB5TCnDrE5xZdtQhU3z9XDwFyO9qopmb%2FyDwE5IwwvMEszCRgiREcaSlBAWp2fjm8mInoxv5iMKdfcwBdBYiMpaAxdktvLazserfy9n%2F9v1twF6Os5XxFPKKUko%2BGlhNGDYDv4B4QrzMWhIUG1SSbOYayNlBN3iseSJUSIVnAj%2Fdkc%2BqCSyKMkoB4I98B3uA%2FlHOR6nPBKg4qMcjT7LeS9HNBz%2BRx35ru7zNVbg%2BE93vzl7e3sH',
#             'Host': 'data.worldbank.org.cn',
#             'If-None-Match': 'W/"3ed70-ZDoDyD/pAoppwhz6LOpE/Q"',
#             'Upgrade-Insecure-Requests': '1',
#             'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_13_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Safari/537.36',
#         }
#
#         res = requests.get(url, headers)
#         if res.status_code == 200:
#             res_utf = res.content.decode('utf-8')
#             # print(res_utf)
#             res_excel = pq(pq(pq(pq(res_utf)('.buttonGroup'))('div'))('a')[2]).attr('href')
#             res_csv = pq(pq(pq(pq(res_utf)('.buttonGroup'))('div'))('a')[0]).attr('href')
#             save_list.append((country, res_excel))
#             print(res_excel)
#             print('\n*****************************************\n')
#     return save_list
#
#
# def download_excel(path):
#     download_list = [url[1] for url in save_excel_url()]
#     with open(os.path.join(path, 'download_excel.sh'), mode='w', encoding='utf-8') as f:
#         for i in download_list:
#             download_str = 'wget {}'.format(i)
#             print(download_str)
#             f.write(download_str + '\n')
#     print('||||||||||||||||||\n下载脚本完成，移步{}运行{}进行下载\n||||||||||||||||||'.format(path, 'download_excel.sh'))
#     script_file = 'sh {}/download_excel.sh'.format(path)
#     os.system(script_file)
#
#
# def download(url, dst):
#     """
#     给定 url，目标路径，stream 下载，附进度条
#     :param url: str，下载 url
#     :param dst: str，目标路径
#     :return: 文件大小
#     """
#     print('-----url---->>', url)
#     try:
#         with requests.get(url, stream=True, timeout=3) as r:
#             if r.status_code == 404:
#                 print('404')
#                 return 0
#             file_size = int(r.headers.get('Content-Length'))
#     except Exception as e:
#         logging.warning(e)
#         return 0
#
#     if os.path.exists(dst):
#         first_byte = os.path.getsize(dst)
#     else:
#         first_byte = 0
#     if first_byte >= file_size:
#         return file_size
#     logging.info('--- %s is downloading... ---' % url)
#     header = {"Range": "bytes=%s-%s" % (first_byte, file_size)}
#     pbar = tqdm.tqdm(
#         total=file_size, initial=first_byte,
#         unit='B', unit_scale=True, desc=url.split('/')[-1])
#     try:
#         req = requests.get(url, headers=header, stream=True, timeout=3)
#     except Exception as e:
#         logging.warning(e)
#         return 0
#     with(open(dst, 'ab')) as f:
#         try:
#             for chunk in req.iter_content(chunk_size=1024):
#                 if chunk:
#                     f.write(chunk)
#                     pbar.update(1024)
#         except Exception as e:
#             logging.warning(e)
#     pbar.close()
#     return file_size
#
#
# if __name__ == '__main__':
#     path = '/data/share/excel/world_bank'
#     download_excel(path)

    #