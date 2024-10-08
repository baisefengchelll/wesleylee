import pandas as pd
import numpy as np

# create a series
s = pd.Series([1, 3, 5, np.nan, 6, 8])
print(s)
# create a dataframe
dates = pd.date_range("20241008", periods=6)
print(dates)

df = pd.DataFrame(np.random.randn(6,4), index=dates, columns=list("ABCD"))
