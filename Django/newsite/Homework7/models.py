from django.db import models
from django.utils import timezone

# Create your models here.
class HW7(models.Model):
	column1 = models.CharField(default='王思正', max_length=20)
	column2 = models.PositiveIntegerField(default=4108056004)
	pub_time = models.DateTimeField(default=timezone.now)

	class Meta:
		ordering = ('-pub_time',)
	def __str__(self):
		return self.name