# Write your MySQL query statement below
select Q1.person_name
from Queue Q1
join Queue Q2
   on Q2.turn <= Q1.turn
group by Q1.person_name , Q1.turn
having (sum(Q2.weight) <= 1000)
order by q1.turn desc
LIMIT 1;
