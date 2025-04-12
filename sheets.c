
int main(int argc, char const *argv[])
{
    int success = 0;
    for (int j = i+1; j < n; j++)
    {
        if (abs(m[i][i] - m[j][i]) < EPS)
        {
            for (int k = 0; k <= n; k++)
            {
                m[i][k] -= m[j][k];
            }
            success = 1;
            break;
        }
        else if (abs(m[i][i] + m[j][i]) < EPS)
        {
            for (int k = 0; k <= n; k++)
            {
                m[i][k] += m[j][k];
            }
            success = 1;
            break;
        }
    }
    if (!success)
    {
        float coef = m[i][i] / m[i+1][i];
        for (int k = 0; k <= n; k++)
        {
            m[i][k] -= m[i+1][k] * coef;
            // m[i+1][k] *= coef;
        }
    }
    
    // float coef = m[i][i] / m[i+1][i];
    // for (int j = 0; j <= n; j++)
    // {
    //     m[i][j] -= m[i+1][j] * coef;
    // }
}