SELECT 
    p.product_id,
    COALESCE(pr.new_price, 10) AS price
FROM (
    SELECT DISTINCT product_id
    FROM Products
) p
LEFT JOIN Products pr
    ON p.product_id = pr.product_id
    AND pr.change_date = (
        SELECT MAX(change_date)
        FROM Products
        WHERE product_id = p.product_id
          AND change_date <= '2019-08-16'
    );