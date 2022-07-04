from django.shortcuts import render
from django.http import HttpResponse, Http404
from mysite.models import Product
import random
from datetime import datetime

# Create your views here.
def about(request, author_no=0):
	quotes = ["AAA", "BBB", "CCC", "DDD", "EEE"]
	quote = random.choice(quotes)
	author_no = author_no
	return render(request, "about.html", locals())
# 	html = '''
# <!DOCTYPE html>
# <html>
# <head>
# 	<meta charset="utf-8">
# 	<title>about me</title>
# </head>
# <body>
# 	<h1>school</h1>
# 	<p>
# 		hi, I'm Ssu
# 	</p>
# </body>
# </html>
# 	'''
# 	return HttpResponse(html)

def listing(request, year=2021, month=3, day=15):
# 	html = '''
# <!DOCTYPE html>
# <html>
# <head>
# 	<meta charset="utf-8">
# 	<title>Mobile</title>
# </head>
# <body>
# 	<h2>Mobile</h2>
# 	<table width='400' border=1 bgcolor="#ccffcc">
# 		{}
# 	</table>
	
# </body>
# </html>
# '''
	d = '{}/{}/{}'.format(year,month,day)
	products = Product.objects.all()
	tags = "<tr><td>item number</td><td>brand name</td><td>price</td><td>size</td></tr>"
	for p in products:
		tags = tags + '<tr><td>{}</td>'.format(p.sku)
		tags = tags + '<td>{}</td>'.format(p.name)
		tags = tags + '<td>{}</td>'.format(p.price)
		tags = tags + '<td>{}</td></tr>'.format(p.get_size_display())
		# for fullname_size in p.SIZES:
		# 	if fullname_size[0] == p.size:
		# 		tags = tags + '<td>{}</td></tr>'.format(fullname_size[1])
	return render(request, "list.html", locals())
	# return HttpResponse(html.format(tags))

def disp_detail(request, sku):
# 	html='''
# <!DOCTYPE html>
# <html>
# <head>
# 	<meta charset="utf-8">
# 	<title>{}</title>
# </head>
# <body>
# 	<h2>{}</h2>
# 	<table width="400" border="1" bgcolor="#ccffcc">
# 		{}
# 	</table>
# 	<a href="/list">back to list</a>
# </body>
# </html>
# '''
	try:
		p = Product.objects.get(sku = sku)
	except Product.DoesNotExist:
		raise Http404("Can't find the item")
	tags = "<tr><td>item number</td><td>{}</td></tr>".format(p.sku)
	tags += "<tr><td>brand name</td><td>{}</td></tr>".format(p.name)
	tags += "<tr><td>price</td><td>{}</td></tr>".format(p.price)
	return render(request, "disp_detail.html", locals())
	# return HttpResponse(html.format(p.name, p.name, tags))

def homepage(request):
	return render(request, 'index.html')

def index(request, tvno=0):
	tv_list = [
		{'name':'東森', 'tvcode':'R2iMq5LKXco'},
		{'name':'TVBS', 'tvcode':'2mCSYvcfhtc'},
		{'name':'民視', 'tvcode':'yguQ1SzPM5U'},
		{'name':'台視', 'tvcode':'xL0ch83RAK8'},
	]
	now = datetime.now()
	hour = now.timetuple().tm_hour
	tvno = tvno
	tv = tv_list[tvno]
	return render(request,'index.html',{'tv':tv, 'now':now, 'hour':hour})

def engtv(request, tvno=0):
	tv_list = [
		{'name':'DW news', 'tvcode':'V9KZGs1MtP4'},
		{'name':'ABC news', 'tvcode':'w_Ma8oQLmSM'},
		{'name':'EURO news', 'tvcode':'sPgqEHsONK8'},
	]
	now = datetime.now()
	tvno = tvno
	tv = tv_list[tvno]
	return render(request,'engtv.html',{'tv':tv, 'now':now})

def carlist(request, maker=0):
	car_maker = ['SAAB', 'Ford', 'Honda', 'Mazda', 'Nissan','Toyota' ]
	car_list = [ [],
	['Fiesta', 'Focus', 'Modeo', 'EcoSport', 'Kuga', 'Mustang'],
	['Fit', 'Odyssey', 'CR-V', 'City', 'NSX'],
	['Mazda3', 'Mazda5', 'Mazda6', 'CX-3', 'CX-5', 'MX-5'],
	['Tida', 'March', 'Livina', 'Sentra', 'Teana', 'X-Trail', 'Juke', 'Murano'],
	['Camry','Altis','Yaris','86','Prius','Vios', 'RAV4', 'Wish']
	 ]
	maker = maker
	maker_name = car_maker[maker]
	cars = car_list[maker]
	return render(request,'carlist.html', locals())

def musictv(request, tvno=0):
	tv_list = [
		{'name':'Jazz lofi', 'tvcode':'kgx4WGK0oNU'},
		{'name':'Chillout Lounge', 'tvcode':'9UMxZofMNbA'},
		{'name':'Study music', 'tvcode':'Ti-GyJS7nsA'},
	]
	now = datetime.now()
	tvno = tvno
	tv = tv_list[tvno]
	return render(request,'musictv.html',locals())