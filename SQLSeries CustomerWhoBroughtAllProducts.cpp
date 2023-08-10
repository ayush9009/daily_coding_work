# Write your MySQL query statement below


select c.customer_id from Customer c Inner Join Product p ON c.product_key=p.product_key GROUP BY c.customer_id HAVING COUNT(DISTINCT c.product_key)=(Select count(product_key) from Product);


# when we you want to use any conditons with group clause then u can use having
