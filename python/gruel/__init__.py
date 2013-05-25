import pmt

for key in dir(pmt):
    newkey = 'pmt_' + key
    setattr(pmt, newkey, getattr(pmt, key))
