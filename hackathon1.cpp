#include <stdio.h>
int n;

int main()
{
    int a[100] = {0};
    int option = -1;

    do
    {
        printf("\n\t\tMENU\n");
        printf("1. Nhap so phan tu va gia tri cho mang.\n");
        printf("2. In ra gia tri cac phan tu trong mang.\n");
        printf("3. Dem so luong cac so nguyen to co trong mang.\n");
        printf("4. Tim gia tri nho thu 2 trong mang.\n");
        printf("5. Them phan tu vao mang.\n");
        printf("6. Xoa phan tu tai mot vi tri cu the.\n");
        printf("7. Sap xep mang theo thu tu giam dan.\n");
        printf("8. Tim phan tu.\n");
        printf("9. Xoa toan bo phan tu trung lap trong mang va hien thi toan bo phan tu doc nhat co o mang.\n");
        printf("10. Dao nguoc thu tu cua cac phan tu trong mang.\n");
        printf("11. Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
        {
            printf("Nhap kich thuoc cua mang: ");
            scanf("%d", &n);

            for (int i = 0; i < n; ++i)
            {
                printf("Nhap phan tu thu %d: ", i + 1);
                scanf("%d", &a[i]);
            }
            break;
        }
        case 2:
        {
            printf("Cac phan tu trong mang: \n");
            for (int i = 0; i < n; ++i)
            {
                printf("a[%d] = %d\n", i, a[i]);
            }
            break;
        }
        case 3:
        {
            int count = 0;
            for (int i = 0; i < n; ++i)
            {
                int prime = 0;
                for (int j = 2; j * j <= a[i]; ++j)
                {
                    if (a[i] % j == 0)
                    {
                        prime = 1;
                    }
                }
                if (!prime && a[i] >= 2)
                {
                    ++count;
                }
            }
            printf("So luong so nguyen to co trong mang: %d", count);
            break;
        }
        case 4:
        {
            int tmp[n];
            for (int i = 0; i < n; ++i)
            {
                tmp[i] = a[i];
            }

            for (int i = n - 1; i > 0; --i)
            {
                int is_swap = 1;
                for (int j = 0; j < i; ++j)
                {
                    if (tmp[j] < tmp[j + 1])
                    {
                        int temp = tmp[j];
                        tmp[j] = tmp[j + 1];
                        tmp[j + 1] = temp;
                        is_swap = 0;
                    }
                }
                if (is_swap == 1)
                    break;
            }
            printf("Phan tu nho thu hai trong mang: %d", tmp[n - 2]);
            break;
        }
        case 5:
        {
            int value, idx;
            do
            {
                printf("Nhap gia tri phan tu can them: ");
                scanf("%d", &value);
                printf("Nhap vi tri can them: ");
                scanf("%d", &idx);
                if (idx <= 0)
                    printf("Vi tri them khong hop le. Nhap lai.\n");
            } while (idx <= 0);

            if (idx > n)
            {
                a[idx - 1] = value;
                n = idx;
            }
            else
            {
                for (int i = n; i >= idx; --i)
                {
                    a[i] = a[i - 1];
                }
                a[idx - 1] = value;
                ++n;
            }
            break;
        }
        case 6:
        {
            int idx;
            do
            {
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &idx);
                if (idx <= 0 || idx > n)
                    printf("Vi tri xoa khong hop le.\n");
            } while (idx <= 0 || idx > n);

            for (int i = idx - 1; i < n - 1; ++i)
            {
                a[i] = a[i + 1];
            }
            --n;
        }
        break;
        case 7:
        {
            for (int i = 1; i < n; ++i)
            {
                int tmp = a[i];
                int j = i - 1;
                while (j >= 0 && a[j] < tmp) ///
                {
                    a[j + 1] = a[j];
                    --j;
                }
                a[j + 1] = tmp;
            }
        }
        break;
        case 8:
        {
            int value;
            printf("Nhap phan tu can tim: ");
            scanf("%d", &value);

            int found = 0;
            int l = 0, r = n - 1;
            while (l <= r)
            {
                int m = (l + r);
                if (a[m] == value)
                {
                    printf("Gia tri %d ton tai trong mang.\n", value);
                    found = 1;
                    break;
                }
                else if (a[m] < value)
                    l = m + 1;
                else
                    r = m - 1;
            }
            if (!found)
                printf("Gia tri %d khong ton tai trong mang.\n", value);
            break;
        }
        case 9:
        {
            int  count = 0;
            int tmp[n];
            for (int i = 0; i < n; ++i)
            {
                tmp[i] = a[i];
            }
            for (int i = 0; i < 10; ++i)
            {
                if (tmp[i] == -1)
                    continue;

                for (int j = i + 1; j < n; ++j)
                {
                    if (tmp[i] == tmp[j])
                    {
                        tmp[j] = -1;
                        count++;
                    }
                }
            }
            for (int i = 0; i < n; ++i)
            {
                if (tmp[i] != -1)
                    printf("%d ", tmp[i]);
            }
            break;  
        }
        case 10:
        {
            int tmp[n];
            for (int i = 0; i < n;++i)
            {
                tmp[i] = a[i];
            }
            for (int i = 0; i < n;++i)
            {
                a[i] = tmp[n-i-1];
            }
            break;
        }
        case 11:
            printf("Tam biet.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
            break;
        }
    } while (option != 11);
}
