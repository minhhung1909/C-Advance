# 4. MEMORY LAYOUT

Chương trình main.c (trên windown) hoặc main.hex (trên vđk) được lưu vào bộ nhớ SSD hoặc Flash. Đối với Windown khi ấn run còn trên VĐK thì bật lên thì lập tức chương trình sẽ được copy vào bộ nhớ RAM để thực thi.

## Text segment

- Quyền: Read-Only, Run
- Chứa chỉ lệnh ngôn ngữ máy.


## Data Segment (Initial data segment)

- Quyền: Read-Write
- Chứa: Biến toàn cục, Static được khởi tạo giá trị khác 0.
- Các biến sẽ được thu hồi khi chương trình kết thúc.

## BSS Segment (Uninitialized Data Segment)

- Quyền: Read-Write
- Chứa: Biến toàn cục, static được khởi tạo giá trị bằng không hoặc không gán giá trị (Không tường minh).
- Các biến sẽ được thu hồi khi chương trình kết thúc.

## Stack

- Quyền: Read-Write
- Chứa: Biến cục bộ và tham số truyền vào. 
- Vùng nhớ này sẽ được thu hồi khi ra khỏi hàm. Bộ nhớ này có tốc độ truy cập nhanh nhất
- Hệ điều hành sẽ quản lý bộ nhớ này.

## Heap

- Quyền: Read-Write
- Chứa: Là vùng nhwos dùng để thực hiện cấp phát động. 
- Vùng nhớ này sẽ không được huỷ khi sử dụng xong nên phải được thu hồi khi thực hiện hàm free().


Stack và Heap là 2 vùng nhớ cố định và có giới hạn nếu không cân nhắc khi sữ dụng dễ xãy ra tình trạng Overflow

