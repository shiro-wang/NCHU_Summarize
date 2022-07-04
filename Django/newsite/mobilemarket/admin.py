from django.contrib import admin
from .models import Maker, PModel, Product, PPhoto
class PModellist(admin.ModelAdmin):
	list_display = ('name', 'id')
# Register your models here.
admin.site.register(Maker)
admin.site.register(PModel, PModellist)
admin.site.register(Product)
admin.site.register(PPhoto)