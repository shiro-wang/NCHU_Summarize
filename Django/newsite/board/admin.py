from django.contrib import admin
from .models import Mood, Post, Contact, User, Profile, Diary
# Register your models here.
class PostAdmin(admin.ModelAdmin):
	list_display = ("nickname", "message", "enabled", "pub_time", "born_year")
	ordering = ('-pub_time',)
admin.site.register(Mood)
admin.site.register(Contact)
admin.site.register(Post, PostAdmin)
admin.site.register(User)
admin.site.register(Profile)
admin.site.register(Diary)