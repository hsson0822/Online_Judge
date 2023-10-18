-- 코드를 입력하세요


SELECT a.title, a.board_id, b.reply_id, b.writer_id, b.contents, DATE_FORMAT(b.CREATED_DATE,'%Y-%m-%d') as created_date
  from used_goods_board a, used_goods_reply b
  where a.board_id = b.board_id and
              a.CREATED_DATE LIKE '2022-10%'
  order by b.created_date, a.title asc;