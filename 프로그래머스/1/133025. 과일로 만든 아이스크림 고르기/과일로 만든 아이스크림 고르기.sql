-- 코드를 입력하세요
SELECT FIRST.FLAVOR
FROM FIRST_HALF FIRST, ICECREAM_INFO ICE
WHERE FIRST.FLAVOR = ICE.FLAVOR AND FIRST.TOTAL_ORDER > 3000 AND ICE.INGREDIENT_TYPE LIKE 'fruit%'
ORDER BY FIRST.TOTAL_ORDER DESC