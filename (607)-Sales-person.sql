# Write your MySQL query statement below
select s.name from 
SalesPerson s LEFT Join Orders o 
ON s.sales_id=o.sales_id
LEFT JOIN Company c 
ON o.com_id=c.com_id 
group by s.sales_id,s.name 
having sum(c.name="RED")=0 
OR sum(c.name="RED") is null;
